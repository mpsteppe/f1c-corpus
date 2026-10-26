int __thiscall sub_599B10(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  char Buffer[256]; // [esp+8h] [ebp-100h] BYREF

  result = sub_598C90((int)a2);
  if ( !result )
  {
    result = a2[34];
    if ( !result )
    {
      if ( a2[39] == -1 )
        sprintf(Buffer, aAlreadyDeleted);
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
      v5 = a2[41];
      if ( v5 )
        *(_DWORD *)(v5 + 168) = a2[42];
      v6 = a2[42];
      if ( v6 )
        *(_DWORD *)(v6 + 164) = a2[41];
      if ( (_DWORD *)this[9] == a2 )
        this[9] = a2[42];
      sub_598580(a2);
      j_nullsub_6(a2);
      sub_5BE8AE();
      result = this[4] - 1;
      this[4] = result;
    }
  }
  return result;
}
