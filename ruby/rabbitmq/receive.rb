#!/usr/bin/env ruby

require 'bunny'

connection = Bunny.new
connection.start

channel = connection.create_channel
queue = channel.queue('hello')


# provide a callback to be executed when RabbitMQ pushes messages to consumer
begin
  puts ' [*] Waiting for messages. To exit press CTRL+C'

  # use blocking thread
  queue.subscribe(block: true) do |_delivery_info, _properties, body|
    puts " [x] Received #{body}"
  end
rescue Interrupt => _
  connection.close

  exit(0)
end
