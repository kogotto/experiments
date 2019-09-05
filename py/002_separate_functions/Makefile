

parsed_to_json: raw_data
	@echo 'dependence $^'
	@echo 'target $@'

	python -c 'import func; func.foo("$@")' > parsed_to_json
