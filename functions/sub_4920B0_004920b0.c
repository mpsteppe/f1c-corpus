int __thiscall sub_4920B0(_DWORD *this)
{
  int v2; // edi
  char v4[256]; // [esp+8h] [ebp-100h] BYREF

  AudioStreamBufferRead(0);
  v2 = 32;
  if ( sub_491FB0(this) )
  {
    do
    {
      if ( sub_5654A0(aSourceMas, v4) && !(unsigned __int8)BitmapLoader(v4) )
      {
        StringFormatWithBufferOverflowCheck(&byte_7CDCF0, "Could Not Load MAS file %s (line %d)", v4, this[99]);
        sub_493C80(1, &byte_7CDCF0);
      }
      --v2;
    }
    while ( v2 >= 0 && sub_491FB0(this) );
  }
  AudioStreamBufferRead(0);
  return 0;
}
