void __thiscall sub_421A90(_DWORD *this)
{
  int v2; // eax

  if ( *(_DWORD *)dword_B72314 != 8 && this[3894] != 4 )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( this[4821] != dword_FADE18 - 1
        && (*(_DWORD *)(*this + 22468) != *(_DWORD *)(dword_91E084 + 22468) || *(_DWORD *)(*this + 21788)) )
      {
        v2 = sub_4FC350(this + 3706);
        if ( !v2 || v2 == 4 || this[4845] == 1 )
        {
          sub_4FF820(this + 3706);
          this[5212] = 1;
        }
      }
    }
    else
    {
      sub_4FF820(this + 3706);
      this[5212] = 1;
    }
  }
}
