void __thiscall sub_45B840(int this)
{
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // ecx
  int v6; // ebp
  int v7; // esi
  double v8; // st7
  int v9; // [esp+10h] [ebp-14h]
  int v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  FloatArrayThresholdSearch();
  v2 = *(_DWORD *)(this + 796);
  v3 = 0;
  v9 = 0;
  *(_BYTE *)(this + 800) = 0;
  v11 = v2;
  UICursorSelectionRectangleRenderWithInterpolatio((float *)this);
  TwinFieldGetter_cf30(&v12, 0);
  v4 = CRTFtol((double)dword_5D6D64 * 0.035);
  v5 = 0;
  v13 = v4;
  v10 = 0;
  while ( 1 )
  {
    v6 = (v5 + v11) % 8;
    v7 = 92 * v6 + this;
    if ( *(float *)(v7 + 144) > 0.0 )
      break;
LABEL_8:
    v10 = ++v5;
    if ( v5 >= 8 )
      return;
  }
  TextRenderDispatcher(v7 + 60, v12 / 2, v3, *(_DWORD *)(v7 + 140), 2, -1.0, -1.0, 0);
  v8 = *(float *)(v7 + 144) - dbl_8AFE90;
  *(float *)(v7 + 144) = v8;
  if ( v8 > 0.0 )
    *(_BYTE *)(this + 800) = 1;
  else
    PerIndexStructFieldResetter((_DWORD *)this, v6);
  v3 += v13;
  if ( ++v9 < 4 )
  {
    v5 = v10;
    goto LABEL_8;
  }
}
