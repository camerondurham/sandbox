#!/usr/bin/ruby -w



class Customer
  @@no_of_customers = 0

  def initialize(id, name, addr)
    @cust_id = id
    @cust_name = name
    @cust_addr = addr
    @@no_of_customers += 1
  end

  def name()
    return @cust_name
  end

  def total_customers()
    puts "Total number of customers: #@@no_of_customers"
  end

end

cust1 = Customer.new("1","Steve","Austin, TX")

puts cust1.name
cust1.total_customers

cust2 = Customer.new("2", "Adam", "Los Angeles, CA")

puts cust2.name
cust2.total_customers


