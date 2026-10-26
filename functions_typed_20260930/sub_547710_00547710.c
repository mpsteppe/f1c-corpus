int __thiscall sub_547710(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _BYTE v7[256]; // [esp+8h] [ebp-100h] BYREF

  result = ReferenceCountedResourceRelease((int)a2);
  if ( !result )
  {
    result = a2[34];
    if ( !result )
    {
      if ( a2[39] == -1 )
        StringFormatWithBufferOverflowCheck(v7, aAlreadyDeleted);
      v4 = a2[39];
      if ( (v4 & 0x20) != 0 )
      {
        if ( (v4 & 0x100) != 0 )
          --this[7];
        else
          --this[8];
      }
      else if ( (v4 & 0x100) != 0 )
      {
        --this[5];
      }
      else
      {
        --this[6];
      }
      v5 = a2[47];
      if ( v5 )
        *(_DWORD *)(v5 + 192) = a2[48];
      v6 = a2[48];
      if ( v6 )
        *(_DWORD *)(v6 + 188) = a2[47];
      if ( (_DWORD *)this[9] == a2 )
        this[9] = a2[48];
      ArrayCleanupWithDualFree(a2);
      EmptyStub_7470(a2);
      FreeWrapper_7bcf(a2);
      result = this[4] - 1;
      this[4] = result;
    }
  }
  return result;
}

