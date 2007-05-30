//
//  IPEvidenceSource.h
//  MarcoPolo
//
//  Created by David Symonds on 29/03/07.
//

#import <Cocoa/Cocoa.h>
#include <SystemConfiguration/SystemConfiguration.h>
#import "EvidenceSource.h"


@interface IPEvidenceSource : EvidenceSource {
	NSLock *lock;
	NSMutableArray *addresses;

	// For SystemConfiguration asynchronous notifications
	SCDynamicStoreRef store;
	CFRunLoopSourceRef runLoop;
}

- (id)init;
- (void)dealloc;

- (void)doUpdate;
- (void)doUpdateWithArg:(id)arg;	// purely for asynchronous updates
- (NSString *)name;
- (BOOL)doesRuleMatch:(NSDictionary *)rule;
- (NSString *)getSuggestionLeadText:(NSString *)type;
- (NSArray *)getSuggestions;

- (NSArray *)getAddresses;

@end