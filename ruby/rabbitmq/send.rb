#!/usr/bin/env ruby

require 'bunny'


# specify ip address using:
# Bunny.new(hostname: 'rabbit.local')
connection = Bunny.new
connection.start

channel = connection.create_channel

queue = channel.queue('hello')

msg='Hello World!'
channel.default_exchange.publish(msg, routing_key: queue.name)
puts " [x] Sent '#{msg}' "

connection.close
