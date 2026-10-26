void __thiscall sub_5FBB60(int this, int a2)
{
  int *v3; // eax
  int v4; // esi
  bool v5; // bl
  _DWORD *v6; // eax
  int v7; // ebx
  int v8; // eax
  int *v9; // eax

  if ( (*(_BYTE *)this & 4) == 0 )
  {
    v3 = *(int **)(this + 532);
    *(_DWORD *)(this + 540) = v3;
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        do
        {
          v5 = (*(_DWORD *)v4 & 0x200) != 0;
          if ( sub_5DAF80((float *)this, a2, (float *)v4) && !v5 )
          {
            if ( *(int *)(*(_DWORD *)(this + 620) + 768) > 0 && (*(_DWORD *)v4 & 0x4000000) != 0 )
              sub_600940(a2, this, v4, *(_DWORD *)(this + 620) + 772);
            v6 = *(_DWORD **)(v4 + 476);
            v7 = v6[4] + 8 * (*v6)++;
            *(_DWORD *)(v7 + 4) = v4;
            *(float *)v7 = sub_5D7980((float *)(v4 + 228), (float *)(a2 + 52));
          }
          v8 = *(_DWORD *)(this + 540);
          if ( !v8 )
            break;
          v9 = *(int **)(v8 + 4);
          *(_DWORD *)(this + 540) = v9;
          if ( !v9 )
            break;
          v4 = *v9;
        }
        while ( *v9 );
      }
    }
  }
}
