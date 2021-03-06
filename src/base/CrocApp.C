#include "CrocApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<CrocApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

CrocApp::CrocApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CrocApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CrocApp::associateSyntax(_syntax, _action_factory);
}

CrocApp::~CrocApp()
{
}

// External entry point for dynamic application loading
extern "C" void CrocApp__registerApps() { CrocApp::registerApps(); }
void
CrocApp::registerApps()
{
  registerApp(CrocApp);
}

// External entry point for dynamic object registration
extern "C" void CrocApp__registerObjects(Factory & factory) { CrocApp::registerObjects(factory); }
void
CrocApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CrocApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CrocApp::associateSyntax(syntax, action_factory); }
void
CrocApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
