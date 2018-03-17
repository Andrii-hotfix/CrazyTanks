import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        consoleApplication: true
        files: [
            "game.cpp",
            "game.h",
            "gameobject.cpp",
            "gameobject.h",
            "main.cpp",
            "map.cpp",
            "map.h",
            "wall.cpp",
            "wall.h",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
