require 'bundler/setup'

Bundler.require(:default)

class TestDataType
  attr_accessor :name, :name_camelized, :name_lower_camelized, :name_for_casting, :assert_function, :test_values, :loop_value, :as_string

  def initialize(name, test_values, loop_value, as_string_values, name_for_casting_override = nil, assert_function = nil)
    self.name = name

    self.name_camelized = name.camelize

    self.name_lower_camelized = name.camelize(:lower)

    if name_for_casting_override.present?
      self.name_for_casting = name_for_casting_override
    else
      self.name_for_casting = name.humanize.downcase
    end

    if assert_function.present?
      self.assert_function = assert_function
    else
      self.assert_function = 'TEST_ASSERT_EQUAL'
    end

    self.test_values = test_values

    self.loop_value = loop_value

    self.as_string = "[" + as_string_values.join(', ') +"]"
  end
end

class Tests < Thor
  include Thor::Actions

  def self.source_root
    File.dirname(__FILE__)
  end

  desc "generate [NAME]", "Generate the test file for all types or the specified type."
  method_options force: :boolean
  def generate(name = nil)
    @types = [
      TestDataType.new('char', ["'A'", "'B'", "'C'", "'D'", "'E'"], '(i % 255)', ["'A'", "'B'", "'C'", "'D'", "'E'"]),
      TestDataType.new('double', ['1.0', '2.0', '3.0', '4.0', '5.0'], 'i', ['1.000000', '2.000000', '3.000000', '4.000000', '5.000000']),
      TestDataType.new('float', ['1.0F', '2.0F', '3.0F', '4.0F', '5.0F'], 'i', ['1.000000', '2.000000', '3.000000', '4.000000', '5.000000']),
      TestDataType.new('int', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('long', ['1L', '2L', '3L', '4L', '5L'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('long_double', ['1.0L', '2.0L', '3.0L', '4.0L', '5.0L'], 'i', ['1.000000', '2.000000', '3.000000', '4.000000', '5.000000']),
      TestDataType.new('long_int', ['1L', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('long_long', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('long_long_int', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('short', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('short_int', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('signed_char', ["'A'", "'B'", "'C'", "'D'", "'E'"], '(i % 255)', ["'A'", "'B'", "'C'", "'D'", "'E'"]),
      TestDataType.new('signed_int', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('signed_long', ['1L', '2L', '3L', '4L', '5L'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('signed_long_int', ['1L', '2L', '3L', '4L', '5L'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('signed_long_long', ['1LL', '2LL', '3LL', '4LL', '5LL'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('signed_long_long_int', ['1LL', '2LL', '3LL', '4LL', '5LL'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('signed_short', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('signed_short_int', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('string', ['"test 1"', '"test 2"', '"test 3"', '"test 4"', '"test 5"'], '"test"', ['\"test 1\"', '\"test 2\"', '\"test 3\"', '\"test 4\"', '\"test 5\"'], 'char*', 'TEST_ASSERT_EQUAL_STRING'),
      TestDataType.new('unsigned', ['1', '2', '3', '4', '5'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('unsigned_char', ["'A'", "'B'", "'C'", "'D'", "'E'"], '(i % 255)', ["'A'", "'B'", "'C'", "'D'", "'E'"]),
      TestDataType.new('unsigned_int', ['1U', '2U', '3U', '4U', '5U'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('unsigned_long', ['1UL', '2UL', '3UL', '4UL', '5UL'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('unsigned_long_int', ['1UL', '2UL', '3UL', '4UL', '5UL'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('unsigned_long_long', ['1ULL', '2ULL', '3ULL', '4ULL', '5ULL'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('unsigned_long_long_int', ['1ULL', '2ULL', '3ULL', '4ULL', '5ULL'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('unsigned_short', ['1U', '2U', '3U', '4U', '5U'], 'i', ['1', '2', '3', '4', '5']),
      TestDataType.new('unsigned_short_int', ['1U', '2U', '3U', '4U', '5U'], 'i', ['1', '2', '3', '4', '5'])
    ]

    if name.present?
      @types = @types.select { |type| type.name == name }
    end

    @types.each do |type|
      @type = type

      template('templates/array_tests.c.erb', "tests/#{type.name}_array_tests.c", force: options[:force])
    end

    @test_names = %w(
      InitialLength
      InitialCapacity
      PushOneElement
      PushCapacityPlusOneElements
      AtZeroLength
      AtExistingElement
      AtLessThanZeroIndex
      AtGreaterThanLengthIndex
      AtLessThanNegativeLengthIndex
      Clear
      ConcatEmptyArrays
      ConcatEmptyArrayToNonEmptyArray
      ConcatNonEmptyArrayToEmptyArray
      ConcatNonEmptyArrayToNonEmptyArray
      CountEmptyArray
      CountNonEmptyArray
      DeleteFromEmptyArray
      DeleteNonExistingElement
      DeleteExistingElement
      DeleteAtZeroLength
      DeleteAtExistingElement
      DeleteAtLessThanZeroIndex
      DeleteAtGreaterThanLengthIndex
      DeleteAtLessThanNegativeLengthIndex
      DropOneEmptyArray
      DropManyEmptyArray
      DropLessThanArrayLength
      DropGreaterThanArrayLength
      EmptyArrayIsEmpty
      NonEmptyArrayIsNotEmpty
      Push
      MultipleElementArrayToString
      SortAscending
    )

    template('templates/all_tests.c.erb', 'tests/all_tests.c', force: options[:force])
  end
end
