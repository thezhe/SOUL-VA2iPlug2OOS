#!/bin/bash

# This script initializes/updates all submodules
# Use with git bash

git submodule foreach git pull origin master
git submodule foreach git submodule update --init --recursive