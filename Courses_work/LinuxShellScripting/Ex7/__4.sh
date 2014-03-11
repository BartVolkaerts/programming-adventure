#!/bin/bash

variable=$(cat /etc/passwd)

variable=$(< /etc/passwd)

echo $variable
