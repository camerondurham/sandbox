#!/usr/bin/ruby

# Make Ruby aware that included files must be searched
# in current directory
$LOAD_PATH << '.'

require 'math_constants'

sqrt_2 = MathConstants::PYTHAGORAS
puts "Sqrt 2 is #{sqrt_2}"

