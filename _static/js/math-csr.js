MathJax = {
  chtml: {
    scale: 1.0,
    matchFontHeight: false
  },
  options: {
    enableMenu: true,
    menuOptions: {
      settings: {
        renderer: 'CHTML',
        scale: 1.0
      }
    }
  }
};

document$.subscribe(() => {
    MathJax.startup.output.clearCache()
    MathJax.typesetClear()
    MathJax.texReset()
    MathJax.typesetPromise()
  })
