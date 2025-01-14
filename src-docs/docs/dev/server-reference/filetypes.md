![META](authors:Nicolas "Duduf" Dufresne;license:GNU-FDL;copyright:2021-2022;updated:2022/01/16)

# Queries for managing file types

## createFileType

`http://your.server/ramses/?createFileType`

Creates a new file type in the database.

**Query attributes:**

- *name*: **string**. The new name.
- *shortName*: **string**. The new shortName. This should be the default file extension.
- *extensions*: **string**. The extensions used by this type, a comma separated list.
- *uuid*: **string** (optionnal). The file type's Universal Unique Identifier.
- *version*: **string**. The version of the client.
- *token*: **string**. The session token returned by [*login*](general.md#login).

**Reply content:**

Empty

**Reply body**:

```json
{
    "accepted": true,
    "query": "createFileType",
    "success": true,
    "message": "File type \".ma\" created.",
    "content": { }
}
```

## getFileTypes

`http://your.server/ramses/?getFileTypes`

Retrieves the list of all file types.

**Query attributes:**

- *token*: **string**. The session token returned with [*login*](general.md#login).

**Reply content:**

The server replies an array of file type information. Each file type is an object with the following attributes:

- *name*: **string**. The name of the file type.
- *shortName*: **string**. The default extension.
- *extensions*: **string**. The extensions used by this type, a comma separated list.
- *previewable*: **int**. Whether this file type is used for previews. 1 or 0.
- *uuid*: **string**. The Universal Unique Identifier of this file type.
- *version*: **string**. The version of the client.
- *token*: **string**. The session token returned by [*login*](general.md#login).

**Reply body**:

```json
{
    "accepted": true,
    "query": "getFileTypes",
    "success": true,
    "message": "File types list retrieved.",
    "content":  [
        {
            "name": "Maya Ascii",
            "shortName": ".ma",
            "extensions": "ma",
            "uuid": "2d7d7e01-671c-11e7-a78f-4ccc6a288527"
        },
        {
            "name": "Maya Binary",
            "shortName": ".mb",
            "extensions": "mb",
            "uuid": "2d7d7e01-671c-11e7-a78f-4ccc6a288527"
        },
        {
            "name": "Image (Jpeg)",
            "shortName": ".jpg",
            "extensions": "jpg,jpeg",
            "uuid": "2d7d7e01-671c-11e7-a78f-4ccc6a288527"
        }
    ]
}
```

## updateFileType

`http://your.server/ramses/?updateFileType`

Update file type info in the database.

**Query attributes:**

- *name*: **string**. The name of the user.
- *shortName*: **string**. The username.
- *comment*: **string**. The new comment.
- *uuid*: **string**. The Universal Unique Identifier of this file type.
- *extensions*: **string**. The extensions used by this type, a comma separated list.
- *previewable*: **int**. Whether this file type is used for previews. 1 or 0.
- *version*: **string**. The version of the client.
- *token*: **string**. The session token returned by [*login*](general.md#login)

**Reply content:**

Empty

**Reply body**:

```json
{
    "accepted": true,
    "query": "updateFileType",
    "success": true,
    "message": "File type \".ma\" updated.",
    "content": { }
}
```

## removeFileType

`http://your.server/ramses/?removeFileType`

Removes a file type from the database.

**Query attributes:**

- *uuid*: **string**. The file type's Universal Unique Identifier.
- *version*: **string**. The version of the client.
- *token*: **string**. The session token returned by [*login*](general.md#login).

**Reply content:**

Empty

**Reply body**:

```json
{
    "accepted": true,
    "query": "removeFileType",
    "success": true,
    "message": "File type uuid123 removed.",
    "content": { }
}
```
