str = "can_have_class"

pascal_case = str.to_s.split(/_/).map do |s|
  s[0,1] = s[0,1].upcase
  s
end.join

puts "Original #{str}"
puts "Pascal #{pascal_case}"

partial = (1..3).chain([4,5])
puts partial.to_a #=> [1,2,3,4,5]

puts

partial = ["Alice", "Bob"].chain(["Charlie"])
puts partial.to_a #=> ["Alice", "Bob","Charlie"]
