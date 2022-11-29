set(ZKOUSKA    ${CMAKE_BINARY_DIR}/zkouska1)
set(INPUT_DIR  ${CMAKE_SOURCE_DIR}/data)

set(INPUT_FILES
  13.1 13.2 13.3 13.4
)

foreach(test ${INPUT_FILES})

  add_test(NAME zkouska1_${test}
    COMMAND ${ZKOUSKA}
    ${INPUT_DIR}/${test}.txt ${CMAKE_BINARY_DIR}/${test}.dat )

  add_test(NAME zkouska1_${test}_diff
    COMMAND diff -s
    ${INPUT_DIR}/${test}.dat ${CMAKE_BINARY_DIR}/${test}.dat )

endforeach(test)
