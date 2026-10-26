int __thiscall sub_4054E0(_DWORD *this, unsigned int a2)
{
  int v3; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // [esp-Ch] [ebp-44h]
  _BYTE v13[4]; // [esp+10h] [ebp-28h] BYREF
  int v14; // [esp+14h] [ebp-24h]
  char v15; // [esp+2Bh] [ebp-Dh]
  int v16; // [esp+30h] [ebp-8h]

  v3 = this[3];
  v4 = 1;
  if ( !v3 || a2 >= this[5] )
    return v4;
  v5 = *(_DWORD *)(this[6] + 4 * a2);
  if ( sub_587F64(v3, v5, 0) )
    return 1;
  if ( !ThreadSafeReadWrapper_803f(v13, 40, 1, this[3]) )
    return 1;
  v4 = 0;
  OneTimeInitializationWithAtexitStyleRegistration();
  v6 = BitfieldExtractFromStruct(v13);
  this[11] = v6;
  if ( v6 == -1 )
    return 1;
  MemoryAllocation_56a0(v13);
  v7 = this[11];
  this[7] = a2;
  this[8] = 0;
  this[10] = v5 + 40;
  if ( !v7 )
  {
    this[9] = v14 + 44;
    return 0;
  }
  if ( v7 == 1 )
  {
    if ( (v15 & 4) != 0 )
      this[9] = v16 + 44;
    else
      v4 = 1;
    v9 = sub_59B650(this[4]);
    v10 = sub_58AE69(v9, aRb);
    v11 = this[10];
    this[14] = v10;
    (*(void (__thiscall **)(_DWORD *, int, _DWORD))(this[13] + 12))(this + 13, v11, 0);
    if ( (unsigned __int8)ThreadedObjectCreatorWithSEH(this + 13, this[10], this[9] - 44) )
      return v4;
    StructInitWithVTableDispatchAndZeroFill(this);
    return 1;
  }
  if ( v7 != 2 )
    return v4;
  v12 = this[3];
  this[9] = v14;
  sub_587F64(v12, v5 + 40, 0);
  return 0;
}
