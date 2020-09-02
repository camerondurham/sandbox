#!/usr/bin/ruby -w

# define a class
class Box
  BOX_COMPANY = "Boxer Inc"

  BOX_WEIGHT = 10

  def initialize(w, h)
    @width, @height = w, h
  end

  def getArea
    @width * @height
  end
end

box1 = Box.new(10,20)

x = box1.getArea()

puts "Area of the box is: #{x}"

puts "Box Company: #{Box::BOX_COMPANY}"

puts "Box weight is #{Box::BOX_WEIGHT}"


# create an uninitialized object

box2 = Box.allocate

# produces error:
# a2 = box2.getArea()
# puts "Area of the uninitialized box is: #{a2}"

puts box2.to_s
