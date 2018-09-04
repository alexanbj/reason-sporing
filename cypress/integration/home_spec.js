describe('Home view', function() {
  beforeEach(() => {
    cy.visit('/');
  });

  it('should render the home page', () => {
    cy.get('[href*="/"]').should('be.visible');
    cy.get('[href*="https://reasonml.github.io/"]').should('be.visible');
  });
});
