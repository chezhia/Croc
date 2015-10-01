[Mesh]
  type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
  dim = 2 # Dimension of the mesh
  nx  =10
  ny = 10 # Number of elements in the x direction
[]

[Variables]
  [./u]
    #Adds a Linear Lagrange variable by default
  [../]
[]

[Kernels]
  [./Examplelaplacian]
    type = Examplelaplacian # A Laplacian operator
    variable = u # Operate on the "pressure" variable from above
  [../]
[]

[BCs]
  [./all]
    type = NeumannBC # Simple u=value BC
    variable = u
    boundary = 'left right top bottom' # Name of a sideset in the mesh
    value = 0.2 # (Pa) From Figure 2 from paper.  First data point for 1mm balls.
  [../]
[]

[Executioner]
  type = Steady # Steady state problem
  solve_type = PJFNK #Preconditioned Jacobian Free Newton Krylov
  petsc_options_iname = '-pc_type -pc_hypre_type' #Matches with the values below
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true # Output Exodus format
[]
