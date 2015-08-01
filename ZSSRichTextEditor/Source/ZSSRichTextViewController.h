//
//  ZSSRichTextEditorViewController.h
//  ZSSRichTextEditor
//
//  Created by Nicholas Hubbard on 11/30/13.
//  Copyright (c) 2013 Zed Said Studio. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  The types of toolbar items that can be added
 */
extern NSString * const ZSSRichTextEditorToolbarBold;
extern NSString * const ZSSRichTextEditorToolbarItalic;
extern NSString * const ZSSRichTextEditorToolbarSubscript;
extern NSString * const ZSSRichTextEditorToolbarSuperscript;
extern NSString * const ZSSRichTextEditorToolbarStrikeThrough;
extern NSString * const ZSSRichTextEditorToolbarUnderline;
extern NSString * const ZSSRichTextEditorToolbarRemoveFormat;
extern NSString * const ZSSRichTextEditorToolbarJustifyLeft;
extern NSString * const ZSSRichTextEditorToolbarJustifyCenter;
extern NSString * const ZSSRichTextEditorToolbarJustifyRight;
extern NSString * const ZSSRichTextEditorToolbarJustifyFull;
extern NSString * const ZSSRichTextEditorToolbarH1;
extern NSString * const ZSSRichTextEditorToolbarH2;
extern NSString * const ZSSRichTextEditorToolbarH3;
extern NSString * const ZSSRichTextEditorToolbarH4;
extern NSString * const ZSSRichTextEditorToolbarH5;
extern NSString * const ZSSRichTextEditorToolbarH6;
extern NSString * const ZSSRichTextEditorToolbarTextColor;
extern NSString * const ZSSRichTextEditorToolbarBackgroundColor;
extern NSString * const ZSSRichTextEditorToolbarUnorderedList;
extern NSString * const ZSSRichTextEditorToolbarOrderedList;
extern NSString * const ZSSRichTextEditorToolbarHorizontalRule;
extern NSString * const ZSSRichTextEditorToolbarIndent;
extern NSString * const ZSSRichTextEditorToolbarOutdent;
extern NSString * const ZSSRichTextEditorToolbarInsertImage;
extern NSString * const ZSSRichTextEditorToolbarInsertLink;
extern NSString * const ZSSRichTextEditorToolbarRemoveLink;
extern NSString * const ZSSRichTextEditorToolbarQuickLink;
extern NSString * const ZSSRichTextEditorToolbarUndo;
extern NSString * const ZSSRichTextEditorToolbarRedo;
extern NSString * const ZSSRichTextEditorToolbarViewSource;
extern NSString * const ZSSRichTextEditorToolbarParagraph;
extern NSString * const ZSSRichTextEditorToolbarAll;
extern NSString * const ZSSRichTextEditorToolbarNone;

@class ZSSBarButtonItem;

/**
 *  The viewController used with ZSSRichTextEditor
 */
@interface ZSSRichTextViewController : UIViewController


/**
 *  The base URL to use for the webView
 */
@property (nonatomic, strong) NSURL *baseURL;

/**
 *  If the HTML should be formatted to be pretty
 */
@property (nonatomic) BOOL formatHTML;

/**
 *  If the keyboard should be shown when the editor loads
 */
@property (nonatomic) BOOL shouldShowKeyboard;

/**
 *  The placeholder text to use if there is no editor content
 */
@property (nonatomic, strong) NSString *placeholder;

/**
 *  Toolbar items to include
 */
@property (nonatomic, strong) NSArray *enabledToolbarItems;

/**
 *  Color to tint the toolbar items
 */
@property (nonatomic, strong) UIColor *toolbarItemTintColor;

/**
 *  Color to tint selected items
 */
@property (nonatomic, strong) UIColor *toolbarItemSelectedTintColor;

/**
 *  Sets the HTML for the entire editor
 *
 *  @param html  HTML string to set for the editor
 *
 */
- (void)setHTML:(NSString *)html;

/**
 *  Returns the HTML from the Rich Text Editor
 *
 */
- (NSString *)getHTML;

/**
 *  Returns the plain text from the Rich Text Editor
 *
 */
- (NSString *)getText;

/**
 *  Inserts HTML at the caret position
 *
 *  @param html  HTML string to insert
 *
 */
- (void)insertHTML:(NSString *)html;

/**
 *  Manually focuses on the text editor
 */
- (void)focusTextEditor;

/**
 *  Manually dismisses on the text editor
 */
- (void)blurTextEditor;

/**
 *  Shows the insert image dialog with optinal inputs
 *
 *  @param url The URL for the image
 *  @param alt The alt for the image
 */
- (void)showInsertImageDialogWithLink:(NSString *)url alt:(NSString *)alt;

/**
 *  Inserts an image
 *
 *  @param url The URL for the image
 *  @param alt The alt attribute for the image
 */
- (void)insertImage:(NSString *)url alt:(NSString *)alt;

/**
 *  Shows the insert link dialog with optional inputs
 *
 *  @param url   The URL for the link
 *  @param title The tile for the link
 */
- (void)showInsertLinkDialogWithLink:(NSString *)url title:(NSString *)title;

/**
 *  Inserts a link
 *
 *  @param url The URL for the link
 *  @param title The title for the link
 */
- (void)insertLink:(NSString *)url title:(NSString *)title;

/**
 *  Gets called when the insert URL picker button is tapped in an alertView
 *
 *  @warning The default implementation of this method is blank and does nothing
 */
- (void)showInsertURLAlternatePicker;

/**
 *  Gets called when the insert Image picker button is tapped in an alertView
 *
 *  @warning The default implementation of this method is blank and does nothing
 */
- (void)showInsertImageAlternatePicker;

/**
 *  Dismisses the current AlertView
 */
- (void)dismissAlertView;

/**
 *  Add a custom UIBarButtonItem by using a UIButton
 */
- (void)addCustomToolbarItemWithButton:(UIButton*)button;

/**
 *  Add a custom ZSSBarButtonItem
 */
- (void)addCustomToolbarItem:(ZSSBarButtonItem *)item;

/**
 *  Scroll event callback with position
 */
- (void)editorDidScrollWithPosition:(NSInteger)position;

@end
