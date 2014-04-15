#!/bin/bash

cd mbed_libs
for D in *; do if [ -d "${D}" ]; then cd "${D}"; hg pull; hg update; cd ..; fi; done
