# RamPipeFile

A file which goes through a [`RamPipe`](ram_pipe.md).

## Static Methods

| Method | Arguments | Description |
| --- | --- | --- |
| **fromDict**<br />▹ *RamPipeFile* | *object* or *dict*: **pipeFileDict** | Returns a *RamPipeFile* instance built using the given object/dict, as the ones returned by [RamDaemonInterface](ram_daemon_interface.md). |

## Methods

| Method | Arguments | Description |
| --- | --- | --- |
| ***constructor*** | *string*: **shortName**,<br />*[RamFileType](ram_filetype.md)*: **fileType**,<br/>*string*: **colorSpace**=`""` | |
| **check**<br />▹ *boolean* | *string*: **filePath** | Checks if the given file can go through this pipe. |
| **colorSpace**<br />▹ *string* | | The color space used through the pipe. |
| **customSettings**<br />▹ *string* | | Can be any string which can be set from the pipeline editor in the [*Ramses Client Application*](../../components/client/index.md). Use this to add more information to configure your pipeline and pass this information to the addons. |
| **getFiles**<br />▹ *list* of *string* | *string*: **folderPath** | Gets all the files which can go through this pipe in the given folder. |
| **fileType**<br />▹ *[RamFileType](ram_filetype.md)* | | The file type used through the pipe. |

____

## API Dev notes

### (Im)mutable data

The data returned by the methods can be either [mutable or immutable](implementation.md#accessing-the-data).

| Method | Type of the returned data |
| --- | --- |
| **colorSpace** | <i class="fa fa-lock"></i> Immutable |
| **customSettings** | <i class="fa fa-lock"></i> Immutable |
| **fileType** | <i class="fa fa-lock"></i> Immutable |

![META](authors:Nicolas "Duduf" Dufresne;license:GNU-FDL;copyright:2021;updated:2021/06/08)