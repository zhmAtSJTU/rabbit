#include "rabbitApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<rabbitApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

rabbitApp::rabbitApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  rabbitApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  rabbitApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  rabbitApp::registerExecFlags(_factory);
}

rabbitApp::~rabbitApp() {}

void
rabbitApp::registerApps()
{
  registerApp(rabbitApp);
}

void
rabbitApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
rabbitApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
rabbitApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
rabbitApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
rabbitApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
rabbitApp__registerApps()
{
  rabbitApp::registerApps();
}

extern "C" void
rabbitApp__registerObjects(Factory & factory)
{
  rabbitApp::registerObjects(factory);
}

extern "C" void
rabbitApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  rabbitApp::associateSyntax(syntax, action_factory);
}

extern "C" void
rabbitApp__registerExecFlags(Factory & factory)
{
  rabbitApp::registerExecFlags(factory);
}
