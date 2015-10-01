#ifndef CROCAPP_H
#define CROCAPP_H

#include "MooseApp.h"

class CrocApp;

template<>
InputParameters validParams<CrocApp>();

class CrocApp : public MooseApp
{
public:
  CrocApp(InputParameters parameters);
  virtual ~CrocApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CROCAPP_H */
