# Script to automagically log in to the Citrix client
#
# Author: Bart Volkaerts
# Date  : 25/4/2014

import os
import sys
import time
import subprocess
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import Select
from selenium.common.exceptions import NoSuchElementException

# Variables
#login = "dmestrin"
#passwd = "RapaljeASML1234$"
#passwd1 = "19366"

#login = "jblanker"
#passwd = "H8nq3Rw#"
#passwd1 = "09071985"

login = "bvolkaer"
passwd = "De4d8EEf~"
passwd1 = "2606"

# Browser stuff
browser = webdriver.Chrome("/home/bart/Citrix/chromedriver")
browser.get("https://cag.asml.com")
#browser.maximize_window()
browser.find_element_by_name("login").send_keys(login)
browser.find_element_by_name("passwd").send_keys(passwd)
browser.find_element_by_name("passwd1").send_keys(passwd1 + sys.argv[1])
browser.find_element_by_css_selector("input[type=submit]").click() 
browser.find_element_by_id("skipWizardLink").click()
browser.find_element_by_id("Desktops_Text").click()
browser.find_element_by_id("desktop_idCitrix.MPS.Desktop.XendesktopPRD.Windows_00207_0020Desktop_0020_0024S3-2").click()

time.sleep(1)

# Login with wfica 
bashCommand = "/opt/Citrix/ICAClient/wfica /home/bart/Downloads/launch.ica"
process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
output = process.communicate()[0]

browser.close()
