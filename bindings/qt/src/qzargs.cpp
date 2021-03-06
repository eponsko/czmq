/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#include "qczmq.h"

///
//  Copy-construct to return the proper wrapped c types
QZargs::QZargs (zargs_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Destroy zargs instance.
QZargs::~QZargs ()
{
    zargs_destroy (&self);
}

///
//  Return program name (argv[0])
const QString QZargs::progname ()
{
    const QString rv = QString (zargs_progname (self));
    return rv;
}

///
//  Return number of positional arguments
size_t QZargs::arguments ()
{
    size_t rv = zargs_arguments (self);
    return rv;
}

///
//  Return first positional argument or NULL
const QString QZargs::first ()
{
    const QString rv = QString (zargs_first (self));
    return rv;
}

///
//  Return next positional argument or NULL
const QString QZargs::next ()
{
    const QString rv = QString (zargs_next (self));
    return rv;
}

///
//  Return first named parameter value, or NULL if there are no named   
//  parameters, or value for which zargs_param_empty (arg) returns true.
const QString QZargs::paramFirst ()
{
    const QString rv = QString (zargs_param_first (self));
    return rv;
}

///
//  Return next named parameter value, or NULL if there are no named    
//  parameters, or value for which zargs_param_empty (arg) returns true.
const QString QZargs::paramNext ()
{
    const QString rv = QString (zargs_param_next (self));
    return rv;
}

///
//  Return current parameter name, or NULL if there are no named
//  parameters.                                                 
const QString QZargs::paramName ()
{
    const QString rv = QString (zargs_param_name (self));
    return rv;
}

///
//  Return value of named parameter, NULL if no given parameter has
//  been specified, or special value for wich zargs_param_empty () 
//  returns true.                                                  
const QString QZargs::paramLookup (const QString &keys)
{
    const QString rv = QString (zargs_param_lookup (self, keys.toUtf8().data()));
    return rv;
}

///
//  Returns true if there are --help -h arguments
bool QZargs::hasHelp ()
{
    bool rv = zargs_has_help (self);
    return rv;
}

///
//  Returns true if parameter did not have a value
bool QZargs::paramEmpty (const QString &arg)
{
    bool rv = zargs_param_empty (arg.toUtf8().data());
    return rv;
}

///
//  Print an instance of zargs.
void QZargs::print ()
{
    zargs_print (self);
    
}

///
//  Self test of this class.
void QZargs::test (bool verbose)
{
    zargs_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
