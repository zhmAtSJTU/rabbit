//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "rabbitTestApp.h"
#include "rabbitApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<rabbitTestApp>()
{
  InputParameters params = validParams<rabbitApp>();
  return params;
}

rabbitTestApp::rabbitTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  rabbitApp::registerObjectDepends(_factory);
  rabbitApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  rabbitApp::associateSyntaxDepends(_syntax, _action_factory);
  rabbitApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  rabbitApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    rabbitTestApp::registerObjects(_factory);
    rabbitTestApp::associateSyntax(_syntax, _action_factory);
    rabbitTestApp::registerExecFlags(_factory);
  }
}

rabbitTestApp::~rabbitTestApp() {}

void
rabbitTestApp::registerApps()
{
  registerApp(rabbitApp);
  registerApp(rabbitTestApp);
}

void
rabbitTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
rabbitTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
rabbitTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
rabbitTestApp__registerApps()
{
  rabbitTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
rabbitTestApp__registerObjects(Factory & factory)
{
  rabbitTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
rabbitTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  rabbitTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
rabbitTestApp__registerExecFlags(Factory & factory)
{
  rabbitTestApp::registerExecFlags(factory);
}
