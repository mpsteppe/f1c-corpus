int __thiscall sub_40D430(int this, int a2, float *a3, float *a4, float a5, int a6, int a7)
{
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // eax
  _DWORD *v12; // ecx
  float *v13; // eax
  float v14[3]; // [esp+4h] [ebp-Ch] BYREF

  if ( sub_40AB70((float *)this, a5, a6, a3, a4, (float *)&a4, v14) )
    return 1;
  v9 = a7;
  if ( !*(_DWORD *)(this + 88) )
  {
    v10 = sub_40A410(*(_DWORD **)(this + 84), a2, *(float *)&a4, a7);
    *(_DWORD *)(this + 88) = v10;
    if ( !v10 )
      return 1;
    *v10 = this;
    v11 = *(_DWORD *)(*(_DWORD *)(this + 88) + 16);
    if ( v11 )
    {
      v12 = *(_DWORD **)(this + 92);
      if ( v12 )
      {
        AIL_set_sample_file(v11, *v12, -1);
        if ( *(_DWORD *)(this + 20) == 1 )
          AIL_set_sample_loop_count(*(_DWORD *)(*(_DWORD *)(this + 88) + 16), 0);
        else
          AIL_set_sample_loop_count(*(_DWORD *)(*(_DWORD *)(this + 88) + 16), 1);
        sub_40A380();
      }
    }
  }
  v13 = a4;
  *(_DWORD *)(*(_DWORD *)(this + 88) + 4) = a2;
  *(_DWORD *)(*(_DWORD *)(this + 88) + 8) = v13;
  *(_BYTE *)(*(_DWORD *)(this + 88) + 12) = 1;
  if ( v9 )
  {
    sub_40CEE0((void *)this);
    *(_BYTE *)(*(_DWORD *)(this + 88) + 12) = 0;
  }
  return 0;
}
