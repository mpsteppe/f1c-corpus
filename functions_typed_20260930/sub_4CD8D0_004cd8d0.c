int __thiscall sub_4CD8D0(_DWORD *this, float a2)
{
  int v3; // ebx
  int result; // eax
  int v5; // ebx
  int i; // ebp
  _DWORD *v7; // edi
  float v8; // [esp+8h] [ebp+4h]

  v8 = a2 * 254.0;
  v3 = (int)v8;
  if ( v3 )
  {
    if ( (int)this[22] > 0 && !this[25] )
      AIWaypointPathCheckerRenderer((int)dword_5EA2C0);
    result = this[25];
    v5 = (v3 << 24) + 0xFFFFFF;
    for ( i = 0; i < result; ++i )
    {
      v7 = *(_DWORD **)(this[26] + 4 * i);
      PixelAttributeWriteToTexture(*v7, 0, v5);
      PixelAttributeWriteToTexture(*v7, 1, v5);
      PixelAttributeWriteToTexture(*v7, 2, v5);
      PixelAttributeWriteToTexture(*v7, 3, v5);
      result = this[25];
    }
  }
  else
  {
    result = this[25];
    if ( result > 0 )
      return sub_4CB5E0(this);
  }
  return result;
}

