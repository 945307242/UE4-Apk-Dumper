//
// Created by Ascarre on 03-08-2022.
//

#ifndef PRIVATE_DUMPER_OFFSETS_H
#define PRIVATE_DUMPER_OFFSETS_H

uint32 MAX_SIZE = 100;
uint32 ClassCount = 0;
uint32 DumpLimit = 300000;

bool isLibDump = false, isFullDump = false, LibDumped = false,
        isUE423 = false, isDecrypt = false, isPubg = false,
        isStringDump = false, StringDumped = false,
        isObjectsDump = false, isObjectsDumped = false,
        isSDKWDump = false, isSDKWDumped = false,
        isSDKDump = false, isSDKDumped = false;

namespace Offsets {

    const char *DumperName = "Private Dumper v4.0";
    const char *ProcessName;
    const char *ModuleName = "libUE4.so";

    uintptr_t PointerSize;

    //Global
    uintptr_t GWorld;
    uintptr_t GNames;
    uintptr_t GUObjectArray;

    uintptr_t GWorldPointer;

    //FNameEntry
    uintptr_t FNameEntryToNameString;

    //FUObjectArray
    uintptr_t FUObjectArrayToTUObjectArray;
    uintptr_t FUObjectItemPadd;
    uintptr_t FUObjectItemSize;

    //TUObjectArray
    uintptr_t TUObjectArrayToNumElements;

    //UObject
    uintptr_t UObjectToInternalIndex;
    uintptr_t UObjectToClassPrivate;
    uintptr_t UObjectToFNameIndex;
    uintptr_t UObjectToOuterPrivate;

    //FNamePool - 4.23+
    uintptr_t FNameStride;
    uintptr_t GNamesToFNamePool;
    uintptr_t FNamePoolToCurrentBlock;
    uintptr_t FNamePoolToCurrentByteCursor;
    uintptr_t FNamePoolToBlocks;

    //FNameEntry - 4.23+
    uintptr_t FNameEntryToLenBit;
    uintptr_t FNameEntryToString;

    //FField - 4.23+
    uintptr_t FFieldToClass;
    uintptr_t FFieldToNext;
    uintptr_t FFieldToName;


    //UField
    uintptr_t UFieldToNext;

    //UStruct
    uintptr_t UStructToSuperStruct;
    uintptr_t UStructToChildren;
    uintptr_t UStructToChildProperties;//V - 4.23+

    //UFunction
    uintptr_t UFunctionToFunctionFlags;
    uintptr_t UFunctionToFunc;

    //UProperty
    uintptr_t UPropertyToElementSize;
    uintptr_t UPropertyToPropertyFlags;
    uintptr_t UPropertyToOffsetInternal;

    //UBoolProperty
    uintptr_t UBoolPropertyToFieldSize;
    uintptr_t UBoolPropertyToByteOffset;
    uintptr_t UBoolPropertyToByteMask;
    uintptr_t UBoolPropertyToFieldMask;

    //UObjectProperty
    uintptr_t UObjectPropertyToPropertyClass;

    //UClassProperty
    uintptr_t UClassPropertyToMetaClass;

    //UInterfaceProperty
    uintptr_t UInterfacePropertyToInterfaceClass;

    //UArrayProperty
    uintptr_t UArrayPropertyToInnerProperty;

    //UMapProperty
    uintptr_t UMapPropertyToKeyProp;
    uintptr_t UMapPropertyToValueProp;

    //USetProperty
    uintptr_t USetPropertyToElementProp;

    //UStructProperty
    uintptr_t UStructPropertyToStruct;

    //UWorld
    uintptr_t UWorldToPersistentLevel;

    //ULevel
    uintptr_t ULevelToAActors;
    uintptr_t ULevelToAActorsCount;

    void PubgMobile() {
#if defined(__LP64__)
        PointerSize = 0x8;

        //Global
        GWorld = 0x120;
        GNames = 0x120;

        GWorldPointer = 0x10;

        //FNameEntry
        FNameEntryToNameString = 0xC;

        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;

        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0xC;

        //Class: UObject
        UObjectToInternalIndex = 0xC;
        UObjectToClassPrivate = 0x10;
        UObjectToFNameIndex = 0x18;
        UObjectToOuterPrivate = 0x20;

        //Class: UField
        UFieldToNext = 0x28;

        //Class: UStruct
        UStructToSuperStruct = 0x30;
        UStructToChildren = UStructToSuperStruct + PointerSize;

        //Class: UFunction
        UFunctionToFunctionFlags = 0x88;
        UFunctionToFunc = UFunctionToFunctionFlags + UFieldToNext;

        //Class: UProperty
        UPropertyToElementSize = 0x34;
        UPropertyToPropertyFlags = 0x38;
        UPropertyToOffsetInternal = 0x44;

        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x70;
        UBoolPropertyToByteOffset = UBoolPropertyToFieldSize + 0x1;
        UBoolPropertyToByteMask = UBoolPropertyToByteOffset + 0x1;
        UBoolPropertyToFieldMask = UBoolPropertyToByteMask + 0x1;

        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x70;

        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x78;

        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x78;

        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x70;

        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x70;
        UMapPropertyToValueProp = UMapPropertyToKeyProp + PointerSize;

        //Class: USetProperty
        USetPropertyToElementProp = 0x70;

        //Class: UStructProperty
        UStructPropertyToStruct = 0x70;

        //Class: UWorld
        UWorldToPersistentLevel = 0x30;

        //Class: ULevel
        ULevelToAActors = 0xB0;
        ULevelToAActorsCount = ULevelToAActors + PointerSize;
#else
        PointerSize = 0x4;

        //Global
        GWorld = 0x120;
        GNames = 0x120;

        GWorldPointer = 0xB8;

        //FNameEntry
        FNameEntryToNameString = 0x8;

        //Class: FUObjectArray
        FUObjectArrayToTUObjectArray = 0x10;

        //Class: TUObjectArray
        TUObjectArrayToNumElements = 0x8;

        //Class: UObject
        UObjectToInternalIndex = 0x8;
        UObjectToClassPrivate = 0xC;
        UObjectToFNameIndex = 0x10;
        UObjectToOuterPrivate = 0x18;

        //Class: UField
        UFieldToNext = 0x1C;

        //Class: UStruct
        UStructToSuperStruct = 0x20;
        UStructToChildren = UStructToSuperStruct + PointerSize;

        //Class: UFunction
        UFunctionToFunctionFlags = 0x58;
        UFunctionToFunc= UFunctionToFunctionFlags + UFieldToNext;

        //Class: UProperty
        UPropertyToElementSize = 0x24;
        UPropertyToPropertyFlags = 0x28;
        UPropertyToOffsetInternal = 0x34;

        //Class: UBoolProperty
        UBoolPropertyToFieldSize = 0x50;
        UBoolPropertyToByteOffset = UBoolPropertyToFieldSize + 0x1;
        UBoolPropertyToByteMask = UBoolPropertyToByteOffset + 0x1;
        UBoolPropertyToFieldMask = UBoolPropertyToByteMask + 0x1;

        //Class: UObjectProperty
        UObjectPropertyToPropertyClass = 0x50;

        //Class: UClassProperty
        UClassPropertyToMetaClass = 0x54;

        //Class: UInterfaceProperty
        UInterfacePropertyToInterfaceClass = 0x54;

        //Class: UArrayProperty
        UArrayPropertyToInnerProperty = 0x50;

        //Class: UMapProperty
        UMapPropertyToKeyProp = 0x50;
        UMapPropertyToValueProp = UMapPropertyToKeyProp + PointerSize;

        //Class: USetProperty
        USetPropertyToElementProp = 0x50;

        //Class: UStructProperty
        UStructPropertyToStruct = 0x50;

        //Class: UWorld
        UWorldToPersistentLevel = 0x20;

        //Class: ULevel
        ULevelToAActors = 0x70;
        ULevelToAActorsCount = ULevelToAActors + PointerSize;
#endif
    };

    void NewGame() {
#if defined(__LP64__)
//For 64 Bit offsets
#else
//For 32 Bit offsets
#endif
    };
}

#endif //PRIVATE_DUMPER_OFFSETS_H
