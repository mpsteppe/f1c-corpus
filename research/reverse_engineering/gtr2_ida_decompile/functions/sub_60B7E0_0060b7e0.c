void __thiscall sub_60B7E0(char *this, int a2)
{
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // edi
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edi
  int v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // edi
  int v21; // eax
  int v22; // edi
  int v23; // eax

  if ( *this < 0 )
  {
    v3 = a2;
    if ( !a2 )
      v3 = *((_DWORD *)this + 6);
    if ( (v3 & 1) != 0 )
    {
      v4 = *((_DWORD *)this + 9);
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 32);
        if ( v5 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 48))(*(_DWORD *)(v4 + 32)) )
            --*(_DWORD *)(v4 + 16);
        }
      }
      *((_DWORD *)this + 14) = 0;
    }
    if ( (v3 & 2) != 0 )
    {
      v6 = *((_DWORD *)this + 10);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 32);
        if ( v7 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 48))(*(_DWORD *)(v6 + 32)) )
            --*(_DWORD *)(v6 + 16);
        }
      }
      *((_DWORD *)this + 15) = 0;
    }
    if ( (v3 & 4) != 0 )
    {
      v8 = *((_DWORD *)this + 11);
      if ( v8 )
      {
        v9 = *(_DWORD *)(v8 + 32);
        if ( v9 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 48))(*(_DWORD *)(v8 + 32)) )
            --*(_DWORD *)(v8 + 16);
        }
      }
      *((_DWORD *)this + 16) = 0;
    }
    if ( (v3 & 0x10) != 0 )
    {
      v10 = *((_DWORD *)this + 12);
      if ( v10 )
      {
        v11 = *(_DWORD *)(v10 + 32);
        if ( v11 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v11 + 48))(*(_DWORD *)(v10 + 32)) )
            --*(_DWORD *)(v10 + 16);
        }
      }
      *((_DWORD *)this + 17) = 0;
    }
    if ( (v3 & 0x20) != 0 )
    {
      v12 = *((_DWORD *)this + 13);
      if ( v12 )
      {
        v13 = *(_DWORD *)(v12 + 32);
        if ( v13 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v13 + 48))(*(_DWORD *)(v12 + 32)) )
            --*(_DWORD *)(v12 + 16);
        }
      }
      *((_DWORD *)this + 18) = 0;
    }
    if ( (v3 & 0x1000) != 0 )
    {
      v14 = *((_DWORD *)this + 8);
      if ( v14 )
      {
        v15 = *(_DWORD *)(v14 + 32);
        if ( v15 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v15 + 48))(*(_DWORD *)(v14 + 32)) )
            --*(_DWORD *)(v14 + 16);
        }
      }
      *((_DWORD *)this + 19) = 0;
    }
    if ( (v3 & 0x8000) != 0 )
    {
      v16 = *((_DWORD *)this + 8);
      if ( v16 )
      {
        v17 = *(_DWORD *)(v16 + 32);
        if ( v17 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v17 + 48))(*(_DWORD *)(v16 + 32)) )
            --*(_DWORD *)(v16 + 16);
        }
      }
      *((_DWORD *)this + 19) = 0;
    }
    if ( (v3 & 0x2000) != 0 )
    {
      v18 = *((_DWORD *)this + 8);
      if ( v18 )
      {
        v19 = *(_DWORD *)(v18 + 32);
        if ( v19 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v19 + 48))(*(_DWORD *)(v18 + 32)) )
            --*(_DWORD *)(v18 + 16);
        }
      }
      *((_DWORD *)this + 19) = 0;
    }
    if ( (v3 & 0x4000) != 0 )
    {
      v20 = *((_DWORD *)this + 8);
      if ( v20 )
      {
        v21 = *(_DWORD *)(v20 + 32);
        if ( v21 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v21 + 48))(*(_DWORD *)(v20 + 32)) )
            --*(_DWORD *)(v20 + 16);
        }
      }
      *((_DWORD *)this + 19) = 0;
    }
    if ( (v3 & 0x20000) != 0 )
    {
      v22 = *((_DWORD *)this + 8);
      if ( v22 )
      {
        v23 = *(_DWORD *)(v22 + 32);
        if ( v23 )
        {
          if ( !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v23 + 48))(*(_DWORD *)(v22 + 32)) )
            --*(_DWORD *)(v22 + 16);
        }
      }
      *((_DWORD *)this + 19) = 0;
    }
    *(_DWORD *)this &= ~0x80u;
  }
}
