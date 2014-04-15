#!/bin/bash

set -e

function color_e {
  echo -e "\e[93m\c"
}

function color_d {
  echo -e "\e[0m\c"
}

function comp_flash {
  echo "Compiling.."
  color_d
  cd picotcp-contrib/"$1"
  make clean && make -j8
  if [[ -d "../../picotcp-rf-test" ]]; then
    folder="picotcp-rf-test"
  elif [[ -d "../../picotcp-v6" ]]; then
    folder="picotcp-v6"
  fi
  color_e
  sudo python ../../"${folder}"/test/acceptancetests/ci/mbed_controller.py flash "$2"&
  spinner $!
}

function spinner {
  s='-\|/'
  i=0
  while kill -0 $1 > /dev/null 2>&1
  do
    i=$(( (i+1) %4 ))
    printf "\r[${s:$i:1}] Flashing.. "
    sleep .2
  done
}

color_e
read -p "Update picotcp? " -n 1 -r
echo ""
if [[ $REPLY =~ ^[Yy]$ ]]; then
  echo "Checking.."
  color_d
  cd picotcp
  git pull
  cd ..
fi

color_e
read -p "Update picotcp-contrib? " -n 1 -r
echo ""
if [[ $REPLY =~ ^[Yy]$ ]]; then
  echo "Checking.."
  color_d
  cd picotcp-contrib
  git pull
  cd ..
fi

color_e
echo "Compile and flash:"
echo "1) test_mbed"
echo "2) test_mbed_duration"
echo "3) test_mbed_lwip"
echo "*) exit"
read -n 1 -r

case "$REPLY" in
  1)  comp_flash "test_mbed" "PicoApp_Robotfw.bin"
      ;;
  2)  comp_flash "test_mbed_duration" "DurationTest.bin"
      ;;
  3)  comp_flash "test_mbed_lwip" "LwIPApp_Robotfw.bin"
      ;;
  *)  ;;
esac

printf "\r\e[92mALL DONE!"
echo ""
color_d
