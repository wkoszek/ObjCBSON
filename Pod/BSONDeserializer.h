//
//  Copyright 2014 Paul Melnikow
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>
#import "bson.h"

@class BSON_OrderedDictionary;

/**
 Private class to handle document serialization
 */
@interface BSONDeserializer : NSObject

+ (NSDictionary *) dictionaryWithNativeDocument:(const bson_t *) bson error:(NSError **) error;

- (id) initWithNativeIterator:(bson_iter_t *) iter;

- (void) appendObject:(id) object forKey:(NSString *) key;
- (void) markCorrupt;
- (void) start;

@property (strong) BSON_OrderedDictionary *dictionary;
@property (assign) BOOL corrupt;
@property (strong) NSError *error;

@end
