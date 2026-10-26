void __thiscall sub_5296C0(int this)
{
  int v2; // esi
  int v3; // esi
  float v4; // [esp+8h] [ebp-8h]
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+Ch] [ebp-4h]

  if ( *(_DWORD *)(this + 296) )
  {
    v4 = 0.0;
    v2 = this;
    while ( 1 )
    {
      v6 = -*(float *)(v2 + 124);
      if ( sub_529A00(0) - 3.5 < v6 )
        break;
      v4 = v4 + *(float *)(v2 + 104);
      *(float *)(this + 284) = v4;
      v2 = *(_DWORD *)(v2 + 296);
      if ( v4 >= 500.0 )
        goto LABEL_7;
    }
    *(float *)(this + 284) = v4;
LABEL_7:
    v5 = 0.0;
    v3 = this;
    while ( sub_529A00(1) + 3.5 <= *(float *)(v3 + 128) )
    {
      v5 = v5 + *(float *)(v3 + 104);
      *(float *)(this + 288) = v5;
      v3 = *(_DWORD *)(v3 + 296);
      if ( v5 >= 500.0 )
        return;
    }
    *(float *)(this + 288) = v5;
  }
}
