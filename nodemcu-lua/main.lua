-- setup I2c and connect display
function init_i2c_display()
     print("--- Initializing display ---")
     -- SDA and SCL can be assigned freely to available GPIOs
     local sda = 5 -- GPIO14
     local scl = 6 -- GPIO12
     local sla = 0x3c
     i2c.setup(0, sda, scl, i2c.SLOW)
     disp = u8g.ssd1306_128x64_i2c(sla)
end

-- the draw() routine
function draw(message)
     disp:setFont(u8g.font_6x10)
     disp:drawStr( 0, 10, message)

end

-- setup the network connection
function init_network()
     ssid = #ssid
     pass = #password
     wifi.setmode(wifi.STATION)
     wifi.sta.config(ssid,pass)

     tmr.alarm(0, 1000, 1, function()
        if wifi.sta.getip() == nil then
           print("Connecting to AP...\n")
        else
           ip, nm, gw=wifi.sta.getip()
           print("IP Info: \nIP Address: ",ip)
           disp:firstPage()
           repeat
               draw(ip)
           until disp:nextPage() == false
           tmr.stop(0)
        end
     end)
end

 -- Start a simple TCP server
function init_tcp_server()
     srv=net.createServer(net.TCP)
     srv:listen(80, function(conn)
          conn:on("receive",function(conn,payload)
          set_pwm(payload)
          print(payload)
          conn:close()
          end)
     end)
end

 -- Start a simple UDP server
function init_udp_server()
     svr=net.createServer(net.UDP)
     svr:on("receive", function(svr, payload)
          set_pwm(payload)
          print(payload)
     end)
     svr:listen(80)
end

function init_gpio_pwm()
     print("Init PWM")
     pwm.setup(1,1000,0)
     pwm.start(1)
     pwm.setup(2,1000,0)
     pwm.start(2)
     pwm.setup(7,1000,0)
     pwm.start(7)
end

function split(s, delimiter)
    result = {};
    for match in (s..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match);
    end
    return result;
end

function set_pwm(value)
     local result = split(value, ",")     

     pwm.setduty(1, result[1])
     pwm.setduty(2, result[2])
     pwm.setduty(7, result[3])
end

init_gpio_pwm()
init_i2c_display()
init_network()
-- init_tcp_server()
init_udp_server()
