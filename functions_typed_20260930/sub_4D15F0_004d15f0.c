int __thiscall sub_4D15F0(int *this)
{
  int result; // eax
  int v3; // esi
  int *v4; // edi
  _BYTE v5[32]; // [esp+8h] [ebp-40h] BYREF
  _BYTE v6[32]; // [esp+28h] [ebp-20h] BYREF

  result = sub_4D1450(this);
  if ( dword_8AFE88 )
  {
    v3 = 0;
    v4 = this + 160;
    do
    {
      StringFormatWithBufferOverflowCheck(v5, "PDOOR%02d", v3);
      *(v4 - 52) = EvaluateSceneNodeProperty(v5, 0);
      StringFormatWithBufferOverflowCheck(v6, "PTENT%02d", v3);
      result = EvaluateSceneNodeProperty(v6, 0);
      *v4 = result;
      ++v3;
      ++v4;
    }
    while ( v3 < 52 );
  }
  return result;
}

