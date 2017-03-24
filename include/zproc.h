/*  =========================================================================
    zproc - process configuration and status

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef ZPROC_H_INCLUDED
#define ZPROC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


//  @warning THE FOLLOWING @INTERFACE BLOCK IS AUTO-GENERATED BY ZPROJECT
//  @warning Please edit the model at "api/zproc.api" to make changes.
//  @interface
//  This is a draft class, and may change without notice. It is disabled in
//  stable builds by default. If you use this in applications, please ask
//  for it to be pushed to stable state. Use --enable-drafts to enable.
#ifdef CZMQ_BUILD_DRAFT_API
//  *** Draft method, for development use, may change without warning ***
//  Create a new zproc.                                        
//  NOTE: On Windows and with libzmq3 and libzmq2 this function
//  returns NULL. Code needs to be ported there.               
CZMQ_EXPORT zproc_t *
    zproc_new (void);

//  *** Draft method, for development use, may change without warning ***
//  Destroy zproc, wait until process ends.
CZMQ_EXPORT void
    zproc_destroy (zproc_t **self_p);

//  *** Draft method, for development use, may change without warning ***
//  Setup the command line arguments, the first item must be an (absolute) filename
//  to run.                                                                        
CZMQ_EXPORT void
    zproc_set_args (zproc_t *self, zlistx_t *args);

//  *** Draft method, for development use, may change without warning ***
//  Connects process stdin with a readable ('>', connect) zeromq socket. If
//  socket argument is NULL, zproc creates own managed pair of inproc      
//  sockets.  The writable one is then accessbile via zproc_stdin method.  
CZMQ_EXPORT void
    zproc_set_stdin (zproc_t *self, void *socket);

//  *** Draft method, for development use, may change without warning ***
//  Connects process stdout with a writable ('@', bind) zeromq socket. If 
//  socket argument is NULL, zproc creates own managed pair of inproc     
//  sockets.  The readable one is then accessbile via zproc_stdout method.
CZMQ_EXPORT void
    zproc_set_stdout (zproc_t *self, void *socket);

//  *** Draft method, for development use, may change without warning ***
//  Connects process stderr with a writable ('@', bind) zeromq socket. If 
//  socket argument is NULL, zproc creates own managed pair of inproc     
//  sockets.  The readable one is then accessbile via zproc_stderr method.
CZMQ_EXPORT void
    zproc_set_stderr (zproc_t *self, void *socket);

//  *** Draft method, for development use, may change without warning ***
//  Return subprocess stdin writable socket. NULL for
//  not initialized or external sockets.             
CZMQ_EXPORT void *
    zproc_stdin (zproc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return subprocess stdout readable socket. NULL for
//  not initialized or external sockets.              
CZMQ_EXPORT void *
    zproc_stdout (zproc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  Return subprocess stderr readable socket. NULL for
//  not initialized or external sockets.              
CZMQ_EXPORT void *
    zproc_stderr (zproc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  process exit code
CZMQ_EXPORT int
    zproc_returncode (zproc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  process exit code
CZMQ_EXPORT int
    zproc_pid (zproc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  return true if process is running, false if not yet started or finished
CZMQ_EXPORT bool
    zproc_running (zproc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  wait or poll process status, return return code
CZMQ_EXPORT int
    zproc_wait (zproc_t *self, bool hang);

//  *** Draft method, for development use, may change without warning ***
//  return internal actor, usefull for the polling if process died
CZMQ_EXPORT void *
    zproc_actor (zproc_t *self);

//  *** Draft method, for development use, may change without warning ***
//  send a signal to the subprocess
CZMQ_EXPORT void
    zproc_kill (zproc_t *self, int signal);

//  *** Draft method, for development use, may change without warning ***
//  set verbose mode
CZMQ_EXPORT void
    zproc_set_verbose (zproc_t *self, bool verbose);

//  *** Draft method, for development use, may change without warning ***
//  Returns CZMQ version as a single 6-digit integer encoding the major
//  version (x 10000), the minor version (x 100) and the patch.        
CZMQ_EXPORT int
    zproc_czmq_version (void);

//  *** Draft method, for development use, may change without warning ***
//  Returns true if the process received a SIGINT or SIGTERM signal.
//  It is good practice to use this method to exit any infinite loop
//  processing messages.                                            
CZMQ_EXPORT bool
    zproc_interrupted (void);

//  *** Draft method, for development use, may change without warning ***
//  Returns true if the underlying libzmq supports CURVE security.
CZMQ_EXPORT bool
    zproc_has_curve (void);

//  *** Draft method, for development use, may change without warning ***
//  Return current host name, for use in public tcp:// endpoints.
//  If the host name is not resolvable, returns NULL.            
//  Caller owns return value and must destroy it when done.
CZMQ_EXPORT char *
    zproc_hostname (void);

//  *** Draft method, for development use, may change without warning ***
//  Move the current process into the background. The precise effect     
//  depends on the operating system. On POSIX boxes, moves to a specified
//  working directory (if specified), closes all file handles, reopens   
//  stdin, stdout, and stderr to the null device, and sets the process to
//  ignore SIGHUP. On Windows, does nothing. Returns 0 if OK, -1 if there
//  was an error.                                                        
CZMQ_EXPORT void
    zproc_daemonize (const char *workdir);

//  *** Draft method, for development use, may change without warning ***
//  Drop the process ID into the lockfile, with exclusive lock, and   
//  switch the process to the specified group and/or user. Any of the 
//  arguments may be null, indicating a no-op. Returns 0 on success,  
//  -1 on failure. Note if you combine this with zsys_daemonize, run  
//  after, not before that method, or the lockfile will hold the wrong
//  process ID.                                                       
CZMQ_EXPORT void
    zproc_run_as (const char *lockfile, const char *group, const char *user);

//  *** Draft method, for development use, may change without warning ***
//  Configure the number of I/O threads that ZeroMQ will use. A good  
//  rule of thumb is one thread per gigabit of traffic in or out. The 
//  default is 1, sufficient for most applications. If the environment
//  variable ZSYS_IO_THREADS is defined, that provides the default.   
//  Note that this method is valid only before any socket is created. 
CZMQ_EXPORT void
    zproc_set_io_threads (size_t io_threads);

//  *** Draft method, for development use, may change without warning ***
//  Configure the number of sockets that ZeroMQ will allow. The default  
//  is 1024. The actual limit depends on the system, and you can query it
//  by using zsys_socket_limit (). A value of zero means "maximum".      
//  Note that this method is valid only before any socket is created.    
CZMQ_EXPORT void
    zproc_set_max_sockets (size_t max_sockets);

//  *** Draft method, for development use, may change without warning ***
//  Set network interface name to use for broadcasts, particularly zbeacon.    
//  This lets the interface be configured for test environments where required.
//  For example, on Mac OS X, zbeacon cannot bind to 255.255.255.255 which is  
//  the default when there is no specified interface. If the environment       
//  variable ZSYS_INTERFACE is set, use that as the default interface name.    
//  Setting the interface to "*" means "use all available interfaces".         
CZMQ_EXPORT void
    zproc_set_biface (const char *value);

//  *** Draft method, for development use, may change without warning ***
//  Return network interface to use for broadcasts, or "" if none was set.
CZMQ_EXPORT const char *
    zproc_biface (void);

//  *** Draft method, for development use, may change without warning ***
//  Set log identity, which is a string that prefixes all log messages sent
//  by this process. The log identity defaults to the environment variable 
//  ZSYS_LOGIDENT, if that is set.                                         
CZMQ_EXPORT void
    zproc_set_log_ident (const char *value);

//  *** Draft method, for development use, may change without warning ***
//  Sends log output to a PUB socket bound to the specified endpoint. To   
//  collect such log output, create a SUB socket, subscribe to the traffic 
//  you care about, and connect to the endpoint. Log traffic is sent as a  
//  single string frame, in the same format as when sent to stdout. The    
//  log system supports a single sender; multiple calls to this method will
//  bind the same sender to multiple endpoints. To disable the sender, call
//  this method with a null argument.                                      
CZMQ_EXPORT void
    zproc_set_log_sender (const char *endpoint);

//  *** Draft method, for development use, may change without warning ***
//  Enable or disable logging to the system facility (syslog on POSIX boxes,
//  event log on Windows). By default this is disabled.                     
CZMQ_EXPORT void
    zproc_set_log_system (bool logsystem);

//  *** Draft method, for development use, may change without warning ***
//  Log error condition - highest priority
CZMQ_EXPORT void
    zproc_log_error (const char *format, ...) CHECK_PRINTF (1);

//  *** Draft method, for development use, may change without warning ***
//  Log warning condition - high priority
CZMQ_EXPORT void
    zproc_log_warning (const char *format, ...) CHECK_PRINTF (1);

//  *** Draft method, for development use, may change without warning ***
//  Log normal, but significant, condition - normal priority
CZMQ_EXPORT void
    zproc_log_notice (const char *format, ...) CHECK_PRINTF (1);

//  *** Draft method, for development use, may change without warning ***
//  Log informational message - low priority
CZMQ_EXPORT void
    zproc_log_info (const char *format, ...) CHECK_PRINTF (1);

//  *** Draft method, for development use, may change without warning ***
//  Log debug-level message - lowest priority
CZMQ_EXPORT void
    zproc_log_debug (const char *format, ...) CHECK_PRINTF (1);

//  *** Draft method, for development use, may change without warning ***
//  Self test of this class.
CZMQ_EXPORT void
    zproc_test (bool verbose);

#endif // CZMQ_BUILD_DRAFT_API
//  @end


#ifdef __cplusplus
}
#endif

#endif
