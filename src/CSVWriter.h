//------------------------------------------------------------------------
//  Copyright 2010 (c) Jeff Brown <spadix@users.sourceforge.net>
//
//  This file is part of the ZBar iPhone App.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//  http://zbar.sourceforge.net/iphone
//------------------------------------------------------------------------

// RFC 4180 CSV generator

@interface CSVWriter
    : NSObject
{
    NSUInteger ncols;
    NSMutableArray *rows;

    NSArray *headerColumns;
    NSString *charset;
    NSStringEncoding encoding;

    NSData *data;
}

- (id) init;
- (id) initWithColumnCount: (NSUInteger) count;
- (void) writeRowWithColumns: (NSArray*) columns;

@property (nonatomic, retain) NSString *charset;
@property (nonatomic, retain) NSArray *headerColumns;
@property (nonatomic, readonly) NSString *MIMEType;
@property (nonatomic, readonly) NSData *data;

@end
