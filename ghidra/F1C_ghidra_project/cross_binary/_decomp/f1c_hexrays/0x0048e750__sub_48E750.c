// f1c  0x0048e750  size=264
int __thiscall sub_48E750(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v5; // eax
  int v6; // ebx
  int v7; // ebp
  int v8; // edi
  float v10; // [esp+0h] [ebp-34h]
  float v11; // [esp+4h] [ebp-30h]
  float v12; // [esp+8h] [ebp-2Ch]
  float v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+30h] [ebp-4h]

  if ( *(_DWORD *)(this[16] + 56) == 2 )
  {
    v5 = this[2];
    v6 = this[1];
    v7 = this[4];
    v8 = this[3];
    v14 = v5;
    if ( this[58] && this[59] )
    {
      v13 = (double)(v5 - v6) * 0.0016666667;
      v12 = (double)(v7 - v8) * 0.00125;
      v11 = (double)(int)this[1] * 0.0016666667;
      v10 = (double)(int)this[3] * 0.00125;
      sub_542200(v10, v11, v12, v13, 0);
      sub_4F9F00(&unk_8AFE18);
      sub_546200(dword_8AFE64);
      sub_4F9F30(&unk_8AFE18);
      sub_542200(0.0, 0.0, 1.0, 1.0, 0);
      sub_541B70(14);
      v5 = v14;
    }
    *a2 = v6;
    *a4 = v8;
    *a3 = v5;
    *a5 = v7;
  }
  return 0;
}
