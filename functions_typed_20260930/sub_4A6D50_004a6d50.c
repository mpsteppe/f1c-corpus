void __thiscall sub_4A6D50(F1CPitMachine *this)
{
  int v2; // ebp
  int v3; // edi
  unsigned __int8 *v4; // ebx

  if ( dword_7C56A4 == 7 )
  {
    if ( *((_DWORD *)this->vehicle + 4112) )
    {
      v2 = *((_DWORD *)this->vehicle + 4111) + 1;
      v3 = 0;
      if ( *(int *)&this->gap_008[344] > 0 )
      {
        v4 = &this->gap_008[348];
        do
        {
          if ( *(_DWORD *)v4 == v2 )
            PitStateChangeRequest(this, 1);
          ++v3;
          v4 += 8;
        }
        while ( v3 < *(_DWORD *)&this->gap_008[344] );
      }
    }
  }
}

