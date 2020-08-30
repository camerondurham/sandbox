class Rectangle
  attr_reader :rect_dims
  def initialize(arr)
    @rect_dims = make_dim_struct(arr)
  end

  def show_size
    puts "Size: #{rect_dims.width}x#{rect_dims.height}"
  end

  RectDims = Struct.new(:width, :height)
  def make_dim_struct(arr)
    RectDims.new(arr[0], arr[1])
  end
end

r1 = Rectangle.new([10,15])
r1.show_size

# WEIRD
# doesn't initialize values properly
# size 1x0
r2 = Rectangle.new(10)
r2.show_size
