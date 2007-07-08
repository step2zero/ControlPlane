//
//  ContextsDataSource.h
//  MarcoPolo
//
//  Created by David Symonds on 3/07/07.
//

#import <Cocoa/Cocoa.h>


@interface Context : NSObject {
	NSString *uuid;
	NSString *parent;	// UUID
	NSString *name;

	// Transient
	NSNumber *depth;
}

- (id)init;
- (id)initWithDictionary:(NSDictionary *)dict;

- (BOOL)isRoot;
- (NSDictionary *)dictionary;
- (NSComparisonResult)compare:(Context *)ctxt;

- (NSString *)uuid;
- (NSString *)parentUUID;
- (void)setParentUUID:(NSString *)parentUUID;
- (NSString *)name;
- (void)setName:(NSString *)newName;

@end


@interface ContextsDataSource : NSObject {
	NSMutableDictionary *contexts;

	// shouldn't _really_ be here
	IBOutlet NSWindow *prefsWindow;
	IBOutlet NSOutlineView *outlineView;
	Context *selection;
}

- (void)loadContexts;
- (void)saveContexts:(id)arg;

- (IBAction)newContext:(id)sender;
- (void)newContextWithName:(NSString *)name;
- (IBAction)removeContext:(id)sender;

- (Context *)contextByUUID:(NSString *)uuid;

- (NSArray *)arrayOfUUIDs;
- (NSArray *)orderedTraversal;
- (NSArray *)walkFrom:(NSString *)src_uuid to:(NSString *)dst_uuid;
- (NSMenu *)hierarchicalMenu;

@end
