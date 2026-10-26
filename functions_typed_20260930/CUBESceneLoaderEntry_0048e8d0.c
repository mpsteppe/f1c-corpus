char __thiscall sub_48E8D0(_DWORD *this)
{
  char *v2; // eax
  char *v3; // eax
  _BYTE v5[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = (char *)this[56];
  if ( !v2 )
    v2 = byte_5EA438;
  if ( !sub_588410(v2, byte_5EA438) )
    return 0;
  LinkedListTraversalWithVirtualCall(this[16]);
  v3 = (char *)this[56];
  if ( !v3 )
    v3 = byte_5EA438;
  if ( !AudioEngineInitialization(this + 58, v3, 0) )
  {
    if ( this[58] )
      this[59] = SimpleGetter_5020();
    if ( this[59] )
    {
      UtilityFunction_1cd0(0, 0, 0.0, 0, 0, 0);
      sub_541CA0(0);
    }
    return 0;
  }
  StringRelocationCopy(0, v5);
  if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_27, 8793) )
    DebugLogWrite(&dword_8AD25C, aCubeErrorLoadi_1);
  return 1;
}

