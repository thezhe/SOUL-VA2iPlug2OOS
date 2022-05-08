#!/bin/bash

# This script updates submodules

echo "Updating submodules..."
git submodule foreach git pull origin master
git submodule foreach git submodule update --init --recursive