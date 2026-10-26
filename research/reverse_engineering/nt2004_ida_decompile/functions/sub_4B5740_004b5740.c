int __thiscall sub_4B5740(_DWORD *this)
{
  int result; // eax
  char Buffer[16]; // [esp+4h] [ebp-10h] BYREF

  result = this[3];
  if ( result )
  {
    result = this[5];
    if ( result )
    {
      if ( *(_DWORD *)(result + 16) )
      {
        sprintf(Buffer, "%c", *(_DWORD *)dword_7667B0 + 33);
        sub_5A3FF0(Buffer, 0, 11, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_7668F4 + 36);
        sub_5A3FF0(Buffer, 42, 11, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_76681C + 39);
        sub_5A3FF0(Buffer, 84, 11, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_766918 + 42);
        sub_5A3FF0(Buffer, 126, 11, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_766864 + 45);
        sub_5A3FF0(Buffer, 168, 11, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_766888 + 48);
        sub_5A3FF0(Buffer, 210, 11, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_7669CC + 62);
        sub_5A3FF0(Buffer, 20, 65, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_7667F8 + 52);
        sub_5A3FF0(Buffer, 62, 65, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_766840 + 55);
        sub_5A3FF0(Buffer, 104, 65, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_7668AC + 58);
        sub_5A3FF0(Buffer, 146, 65, *(_DWORD *)(this[5] + 16), 0);
        sprintf(Buffer, "%c", *(_DWORD *)dword_766978 + 60);
        return sub_5A3FF0(Buffer, 188, 65, *(_DWORD *)(this[5] + 16), 0);
      }
    }
  }
  return result;
}
