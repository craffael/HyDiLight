
add_executable(examples.lecturedemos.convergencestudies.twopointbvp twopointbvp.cc)
target_link_libraries(examples.lecturedemos.convergencestudies.twopointbvp
    PUBLIC Eigen3::Eigen
    Boost::program_options
    lf.quad
)
set_target_properties(examples.lecturedemos.convergencestudies.twopointbvp PROPERTIES FOLDER "examples")
add_custom_target(examples.lecturedemos.convergencestudies.twopointbvp_run
    COMMAND examples.lecturedemos.convergencestudies.twopointbvp -o ${CMAKE_CURRENT_BINARY_DIR}/results.csv && python3 ${CMAKE_CURRENT_SOURCE_DIR}/twopointbvp_plot.py ${CMAKE_CURRENT_BINARY_DIR}/results.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/twopointbvp_plot.py
)
add_dependencies(examples_run examples.lecturedemos.convergencestudies.twopointbvp_run)
set_target_properties(examples_run examples.lecturedemos.convergencestudies.twopointbvp_run PROPERTIES FOLDER "examples")


add_executable(examples.lecturedemos.convergencestudies.linquadlagrfe linquadlagrfe.cc)
target_link_libraries(examples.lecturedemos.convergencestudies.linquadlagrfe
    PUBLIC Eigen3::Eigen
    Boost::program_options
    lf.base
    lf.uscalfe
    lf.mesh
    lf.mesh.utils
    lf.mesh.hybrid2d
    lf.assemble
    lf.quad
    lf.io
)
set_target_properties(examples.lecturedemos.convergencestudies.linquadlagrfe PROPERTIES FOLDER "examples")
add_custom_target(examples.lecturedemos.convergencestudies.linquadlagrfe_run
    COMMAND examples.lecturedemos.convergencestudies.linquadlagrfe -o ${CMAKE_CURRENT_BINARY_DIR}/results.csv && python3 ${CMAKE_CURRENT_SOURCE_DIR}/linquadlagrfe_plot.py ${CMAKE_CURRENT_BINARY_DIR}/results.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linquadlagrfe_plot.py
)
add_dependencies(examples_run examples.lecturedemos.convergencestudies.linquadlagrfe_run)
set_target_properties(examples_run examples.lecturedemos.convergencestudies.linquadlagrfe_run PROPERTIES FOLDER "examples")

add_executable(examples.lecturedemos.convergencestudies.linquadfelshaped linquadfelshaped.cc)
target_link_libraries(examples.lecturedemos.convergencestudies.linquadfelshaped
    PUBLIC Eigen3::Eigen
    Boost::program_options
    lf.base
    lf.uscalfe
    lf.mesh
    lf.mesh.utils
    lf.mesh.hybrid2d
    lf.assemble
    lf.quad
    lf.io
)
set_target_properties(examples.lecturedemos.convergencestudies.linquadfelshaped PROPERTIES FOLDER "examples")
add_custom_target(examples.lecturedemos.convergencestudies.linquadfelshaped_run
    COMMAND examples.lecturedemos.convergencestudies.linquadfelshaped -o ${CMAKE_CURRENT_BINARY_DIR}/results.csv && python3 ${CMAKE_CURRENT_SOURCE_DIR}/linquadfelshaped_plot.py ${CMAKE_CURRENT_BINARY_DIR}/results.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linquadfelshaped_plot.py
)
add_dependencies(examples_run examples.lecturedemos.convergencestudies.linquadfelshaped_run)
set_target_properties(examples_run examples.lecturedemos.convergencestudies.linquadfelshaped_run PROPERTIES FOLDER "examples")

add_executable(examples.lecturedemos.convergencestudies.prefinement prefinement.cc)
target_link_libraries(examples.lecturedemos.convergencestudies.prefinement
    PUBLIC Eigen3::Eigen
    Boost::program_options
    lf.base
    lf.uscalfe
    lf.mesh
    lf.mesh.utils
    lf.mesh.hybrid2d
    lf.assemble
    lf.quad
    lf.io
    lf.refinement
)
set_target_properties(examples.lecturedemos.convergencestudies.prefinement PROPERTIES FOLDER "examples")
add_custom_target(examples.lecturedemos.convergencestudies.prefinement_run
    COMMAND examples.lecturedemos.convergencestudies.prefinement -o ${CMAKE_CURRENT_BINARY_DIR}/results.csv -p 19 && python3 ${CMAKE_CURRENT_SOURCE_DIR}/prefinement_plot.py ${CMAKE_CURRENT_BINARY_DIR}/results.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/prefinement_plot.py
)
add_dependencies(examples_run examples.lecturedemos.convergencestudies.prefinement_run)
set_target_properties(examples_run examples.lecturedemos.convergencestudies.prefinement_run PROPERTIES FOLDER "examples")

add_executable(examples.lecturedemos.convergencestudies.asymptotic asymptotic.cc)
target_link_libraries(examples.lecturedemos.convergencestudies.asymptotic
    PUBLIC Eigen3::Eigen
    Boost::program_options
    lf.quad
)
set_target_properties(examples.lecturedemos.convergencestudies.asymptotic PROPERTIES FOLDER "examples")
add_custom_target(examples.lecturedemos.convergencestudies.asymptotic_run
    COMMAND examples.lecturedemos.convergencestudies.asymptotic -o ${CMAKE_CURRENT_BINARY_DIR}/results.csv && python3 ${CMAKE_CURRENT_SOURCE_DIR}/asymptotic_plot.py ${CMAKE_CURRENT_BINARY_DIR}/results.csv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/asymptotic_plot.py
)
add_dependencies(examples_run examples.lecturedemos.convergencestudies.asymptotic_run)
set_target_properties(examples_run examples.lecturedemos.convergencestudies.asymptotic_run PROPERTIES FOLDER "examples")
