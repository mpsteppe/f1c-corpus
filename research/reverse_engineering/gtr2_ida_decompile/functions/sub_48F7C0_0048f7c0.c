void __thiscall sub_48F7C0(void *this)
{
  int v2; // esi
  double v3; // st7
  double v4; // st7
  int v5; // ebx
  int v6; // edi
  int v7; // ebp
  unsigned __int64 v8; // rax
  int v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // eax
  float v15; // [esp+8h] [ebp-1Ch]
  float v16; // [esp+Ch] [ebp-18h]
  float v17; // [esp+10h] [ebp-14h]
  float v18; // [esp+14h] [ebp-10h]
  float v19; // [esp+18h] [ebp-Ch]
  float v20; // [esp+18h] [ebp-Ch]
  float v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]

  v2 = sub_523980(&dword_BE120C);
  v22 = v2;
  if ( v2 > 0 )
  {
    v16 = sub_521070(&dword_BE120C);
    v3 = sub_521080(&dword_BE120C) - v16;
    v19 = v3;
    if ( v3 > 0.0 )
    {
      v17 = (float)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 4))(this);
      v18 = (float)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 12))(this);
      v15 = (float)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 8))(this);
      v4 = (double)(*(int (__thiscall **)(void *))(*(_DWORD *)this + 16))(this) - v15;
      v5 = (unsigned __int64)(0.1 * v4 + v15);
      v6 = 0;
      v7 = (unsigned __int64)(v4 * 0.89999998 + v15);
      v20 = 1.0 / v19;
      do
      {
        v21 = v18 - v17;
        v8 = (unsigned __int64)((sub_523990(v6) - v16) * v20 * v21 + v17);
        v9 = v8;
        v10 = sub_4DDFE0(&unk_B6E2A0, HIDWORD(v8));
        sub_4DDDB0(v9 - 1, v5, v9 - 1, v7, &word_FF3366, v10);
        v12 = sub_4DDFE0(&unk_B6E2A0, v11);
        sub_4DDDB0(v9, v5, v9, v7, &unk_AA2255, v12);
        v14 = sub_4DDFE0(&unk_B6E2A0, v13);
        sub_4DDDB0(v9 + 1, v5, v9 + 1, v7, 4465186, v14);
        ++v6;
      }
      while ( v6 < v22 );
    }
  }
}
