describe('404 view', function() {
  beforeEach(() => {
    cy.visit('/fgkfmslf');
  });

  it('should render the pretty 404 page', () => {
    cy.get('img[src^="/undraw_lost_bqr2.svg"]').should('be.visible');
  });
});
