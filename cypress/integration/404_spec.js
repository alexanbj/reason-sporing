describe('404 view', function() {
  beforeEach(() => {
    cy.visit('/fgkfmslf');
  });

  it('should render the pretty 404 page', () => {
    cy.get('#86b9c162-e770-4ffa-9cda-84e615f7dc7a').should('be.visible');
  });
});
