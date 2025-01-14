# RamItem

Base class for [*RamAsset*](ram_asset.md) and [*RamShot*](ram_shot.md). An item of the project, either an asset or a shot.

Inherits: [***RamObject***](ram_object.md)

Inherited by: *[RamShot](ram_shot.md), [RamAsset](ram_asset.md)*

## Static Methods

| Method | Arguments | Description |
| --- | --- | --- |
| **fromPath**<br />▹ *RamShot* or *RamAsset* or *RamItem* or *None* | *string*: **fileOrFolderPath**<br /> | Returns either a *RamShot*, *RamAsset* or *RamItem* instance built using the given folder path. The path can be any file or folder path from the asset (a version file, a preview file, etc).<br />The type (shot, asset or general item) can be checked with `RamItem.itemType()` |

## Methods

| Method | Arguments | Description |
| --- | --- | --- |
| ***constructor*** | *string*: **itemName**,<br />*string*: **itemShortName**,<br />*string*: **itemFolder**=`""`,<br />*ItemType*: **itemType**=`ItemType.GENERAL` | |
| **currentStatus**<br />▹ *RamStatus* | *[RamStep](ram_step.md)* or *string*: **step**=`""`,<br />*string*: **resource** = `""` | The current status for the given step |
| **folderPath**<br />▹ *string* |  | The absolute path to the folder containing the item |
| **isPublished**<br />▹ *bool* | *[RamStep](ram_step.md)* or *string*: **step**=`""` | Convenience function to check if there are published files in the publish folder. Equivalent to `len(self.publishedVersionFolderPaths(step, resource)) > 0` |
| **itemType**<br />▹ *ItemType* | | The type of this item. One of `ItemType.SHOT`, `ItemType.ASSET`, `ItemType.GENERAL` |
| **latestPublishedVersionFolderPath**<br />▹ *string* | *[RamStep](ram_step.md)* or *string*: **step**=`""`,<br />*string*: **fileName** = `""`,<br />*string*: **resource** = `undefined` | Folder of the latest published version, for a specific file name and/or resource |
| **latestVersion**<br />▹ *integer* | *string*: **resource** = `""`,<br />*string*: **state** = `""`,<br />*[RamStep](ram_step.md)* or *string*: **step***=`""` | Returns the highest version number for the given state (wip, pub...). |
| **latestVersionFilePath**<br />▹ *string* | *string*: **resource** = `""`,<br />*string*: **state** = `""`,<br />*[RamStep](ram_step.md)* or *string*: **step**=`""` | Latest version file path |
| **previewFolderPath**<br />▹ *string* | *[RamStep](ram_step.md)* or *string*: **step**=`""` | Gets the path to the preview folder. Paths are relative to the root of the item folder. |
| **previewFilePaths**<br />▹ *list of string* | *string*: **resource** = `""`,<br />*[RamStep](ram_step.md)* or *string*: **step**=`""` | Gets the list of file paths in the preview folder. Paths are relative to the root of the item folder. |
| **project**<br />▹ *[RamProject](ram_project.md)* | | Gets the project this item belongs too. To improve performance, if only the shortName is needed, prefer using `projectShortName()` |
| **projectShortName**<br />▹ *string* | | Gets the short name of the project this item belongs too. |
| **publishedVersionFolderPaths**<br />▹ *list of string* | [RamStep](ram_step.md)* or *string*: **step**=`""`,<br />*string*: **fileName** = `""`,<br />*string*: **resource** = `undefined` | Gets the list of folder paths in the publish folder, optionally for a given specific file name and/or resource. |
| **publishFolderPath**<br />▹ *string* | *[RamStep](ram_step.md)* or *string*: **step**=`""` | Gets the path to the publish folder. Paths are relative to the root of the item folder. |
| **setStatus** | *[RamStatus](ram_status.md)*: **status**,<br />*[RamStep](ram_step.md)* or *string*: **step** | Sets the current status for the given step |
| **status**<br />▹ *[RamStatus](ram_status.md)* | *[RamStep](ram_step.md)*: **step** | Gets the current status for the given step |
| **stepFilePath**<br />▹ *string* | *string*: **resource** = `""`,<br />*string*: **extension**=`""`,<br/>*[RamStep](ram_step.md) or string*: **step***=`""` | Gets the file used for this step with the given file extension. |
| **stepFilePaths**<br />▹ *list* of *string* | *[RamStep](ram_step.md) or string*: **step***=`""` | Gets the files used for this step (there may be several files, one per resource) |
| **stepFolderPath**<br />▹ *string* | *[RamStep](ram_step.md) or string*: **step***=`""` | The subfolder for the given step |
| **steps**<br />▹ *list of [RamStep](ram_step.md)* | | Gets the list of steps concerning this item. |
| **versionFilePaths**<br />▹ *string* | *string*: **resource** = `""`,<br />*[RamStep](ram_step.md)* or *string*: **step**=`""` | Gets all version files for the given resource. |
| **versionFolderPath**<br />▹ *string* | *[RamStep](ram_step.md)* or *string*: **step**=`""` | Path to the version folder relative to the item root folder |

____

## API Dev notes

!!! note
    These section is for the development of the API only; you should not need these when developping your add-on using the API.

### (Im)mutable data

The data returned by the methods can be either [mutable or immutable](implementation.md#accessing-the-data).

| Method | Type of the returned data |
| --- | --- |
| **currentStatus** | <i class="fa fa-lock"></i> Immutable |
| **folderPath** | <i class="fa fa-lock"></i> Immutable |
| **isPublished** | <i class="fa fa-pen"></i> Mutable |
| **latestVersion** | <i class="fa fa-pen"></i> Mutable |
| **previewFolderPath** | <i class="fa fa-lock"></i> Immutable |
| **previewFilePaths** | <i class="fa fa-pen"></i> Mutable |
| **publishedFolderPath** | <i class="fa fa-lock"></i> Immutable |
| **publishedFilePaths** | <i class="fa fa-pen"></i> Mutable |
| **status** | <i class="fa fa-pen"></i> Mutable |
| **versionFolderPath** | <i class="fa fa-lock"></i> Immutable |
| **versionFilePath** | <i class="fa fa-pen"></i> Mutable |
| **wipFolderPath** | <i class="fa fa-lock"></i> Immutable |
| **wipFilePath** | <i class="fa fa-pen"></i> Mutable |

![META](authors:Nicolas "Duduf" Dufresne;license:GNU-FDL;copyright:2021;updated:2021/05/07)