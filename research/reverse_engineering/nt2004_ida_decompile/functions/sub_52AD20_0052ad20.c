int __thiscall sub_52AD20(int this)
{
  const char *v2; // eax
  int result; // eax
  int v4; // [esp+4h] [ebp-10Ch] BYREF
  int v5; // [esp+8h] [ebp-108h] BYREF
  int v6; // [esp+Ch] [ebp-104h] BYREF
  char Buffer[256]; // [esp+10h] [ebp-100h] BYREF

  sub_52B930();
  if ( !dword_767454[0] )
  {
    sub_52B9A0(0.0, 432000.0);
    v2 = dword_62A0C8;
    if ( !dword_62A0C8 )
      v2 = &byte_629120;
    sprintf(Buffer, "%sweather.txt", v2);
    sub_52CAF0(Buffer);
  }
  *(_DWORD *)(this + 160) = -1082130432;
  *(_DWORD *)(this + 20) = -1082130432;
  *(_DWORD *)(this + 12) = 1065353216;
  sub_595C00(&v6, &v4, &v5);
  *(float *)(this + 164) = (double)v6 * 0.0039215689;
  *(float *)(this + 168) = (double)v4 * 0.0039215689;
  *(float *)(this + 172) = (double)v5 * 0.0039215689;
  sub_595C40(this + 176, this + 180);
  sub_595C70(this + 184);
  result = sub_529DB0((float *)(this + 192));
  *(_BYTE *)(this + 380) = 0;
  return result;
}
