/* RTcmix - Copyright (C) 2011  The RTcmix Development Team
   See ``AUTHORS'' for a list of contributors. See ``LICENSE'' for
   the license to this software and for a DISCLAIMER OF ALL WARRANTIES.
*/
#import "DisplayWindowAppDelegate.h"
#import "comm.h"

@implementation DisplayWindowAppDelegate

@synthesize window;

- (void) applicationDidFinishLaunching: (NSNotification *) aNotification
{
	initialize();
}

- (void) applicationWillTerminate: (NSNotification *) aNotification
{
	finalize();
}

- (BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication *) sender
{
	return YES;
}

@end
