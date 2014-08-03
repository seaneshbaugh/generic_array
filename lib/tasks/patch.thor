require 'bundler/setup'

Bundler.require(:default)

class Patch < Thor
  include Thor::Actions

  def self.source_root
    File.dirname(__FILE__)
  end

  desc "unity_malloc", "Patch unity_fixture_malloc_overrides.h to not include the overrides."
  method_options force: :boolean
  def unity_malloc
    template('templates/unity_fixture_malloc_overrides.h.erb', "tests/unity/extras/fixture/src/unity_fixture_malloc_overrides.h", force: options[:force])
  end
end
